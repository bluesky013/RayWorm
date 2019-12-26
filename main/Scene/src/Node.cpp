
#include <Node.h>

namespace RayWorm {
namespace Scene {

void Node::addChild(Node& node)
{
    auto iter = std::find(children.begin(), children.end(), &node);
    if (iter != children.end()) {
        return;
    }
    children.emplace_back(&node);
    node.parent = this;
}

void Node::removeChild(Node& node)
{
    auto iter = std::find(children.begin(), children.end(), &node);
    if (iter != children.end()) {
        (*iter)->parent = nullptr;
        children.erase(iter);
    }
}

void Node::setPosition(const glm::vec3& value)
{
    position = value;
}

void Node::setScale(const glm::vec3& value)
{
    scale = value;
}

void Node::setOrientation(const glm::quat& value)
{
    oriention = value;
}

glm::mat4 Node::getTransform() const
{
    glm::mat4 transform;
    transform = glm::mat4_cast(oriention) * transform;
    transform = glm::scale(transform, scale);
    transform = glm::translate(transform, position);
}

}
}