#include <QtWidgets>
#include <iostream>
#include <cmath>

#include "link.h"
#include "node.h"

namespace {

Node *find_node(const std::map<int, Node *> &nodeList, int index)
{
    auto iter = nodeList.find(index);
    if (iter == nodeList.end())
        return NULL;
    return iter->second;
}

}

Link::Link(Node *fromNode, Node *toNode)
{
    myFromNode = fromNode;
    myToNode = toNode;

    myFromNode->addLink(this);
    myToNode->addLink(this);

    setFlags(QGraphicsItem::ItemIsSelectable);
    setZValue(-1);

    setColor(Qt::darkRed);
    trackNodes();
}

Link::~Link()
{
    myFromNode->removeLink(this);
    myToNode->removeLink(this);
}

Node *Link::fromNode() const
{
    return myFromNode;
}

Node *Link::toNode() const
{
    return myToNode;
}

void Link::setColor(const QColor &color)
{
    setPen(QPen(color, 1.0));
}

QColor Link::color() const
{
    return pen().color();
}

void Link::trackNodes()
{
    setLine(QLineF(myFromNode->pos(), myToNode->pos()));
}

Link *Link::newFromJson(nlohmann::json &json, const std::map<int, Node *> &nodeList)
{
    auto from = json["from"];
    if (!from.is_number()) {
        std::cerr << "invalid json of link, no from property\n";
        return NULL;
    }

    auto fromNode = find_node(nodeList, from.get<int>());
    if (!fromNode) {
        std::cerr << "invalid link from index\n";
        return NULL;
    }

    auto to = json["to"];
    if (!to.is_number()) {
        std::cerr << "invalid json of link, no to property\n";
        return NULL;
    }

    auto toNode = find_node(nodeList, to.get<int>());
    if (!toNode) {
        std::cerr << "invalid link to index\n";
        return NULL;
    }

    return new Link(fromNode, toNode);
}

nlohmann::json Link::toJson()
{
    nlohmann::json obj = {
        {"from", fromNode()->index()},
        {"to", toNode()->index()}
    };

    return obj;
}

double Link::length() const
{
    auto x1 = fromNode()->x();
    auto y1 = fromNode()->y();
    auto x2 = toNode()->x();
    auto y2 = toNode()->y();

    auto dist_square = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    return sqrt(dist_square);
}

