#ifndef LINK_H
#define LINK_H

#include <QGraphicsLineItem>
#include "nlohmann/json.hpp"

class Node;

class Link : public QGraphicsLineItem
{
public:
    Link(Node *fromNode, Node *toNode);
    ~Link();

    Node *fromNode() const;
    Node *toNode() const;

    void setColor(const QColor &color);
    QColor color() const;

    void trackNodes();

    static Link *newFromJson(nlohmann::json &json, const std::map<int, Node *> &nodeList);
    nlohmann::json toJson();

    double length() const;

private:
    Node *myFromNode;
    Node *myToNode;
};

#endif
