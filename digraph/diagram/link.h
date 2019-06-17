#ifndef LINK_H
#define LINK_H

#include <QGraphicsLineItem>
#include "nlohmann/json.hpp"

class Node;

class Link : public QGraphicsLineItem
{
public:
    Link(Node *fromNode, Node *toNode, bool bidirect = false);
    ~Link();

    Node *fromNode() const;
    Node *toNode() const;

    void setColor(const QColor &color);
    QColor color() const;

    void setBidirect(bool bidirect);
    bool isBidirected() const;

    void trackNodes();

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);

    void turnRound();

    static Link *newFromJson(nlohmann::json &json, const std::map<int, Node *> &nodeList);
    nlohmann::json toJson();
	
private:
    Node *myFromNode;
    Node *myToNode;
    bool bidirected = false;
};

#endif
