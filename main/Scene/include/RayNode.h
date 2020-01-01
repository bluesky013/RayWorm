#ifndef RAY_NODE_H
#define RAY_NODE_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <vector>

namespace RayWorm {
namespace Scene {

class Node {
public:
    Node(const std::string& nm) : name(nm) {}
    virtual ~Node() {}

    void addChild(Node& node);

    void removeChild(Node& node);

    void setPosition(const glm::vec3& value);

    void setScale(const glm::vec3& value);

    void setOrientation(const glm::quat& value);

    glm::mat4 getTransform() const;

    const std::string& getName() const { return name; }

    void setName(const std::string& nm) { name = nm; }

    const std::vector<Node*>& getChildren() const { return children; }

    Node* getParent() const { return parent; }

private:
    std::string name;
    glm::vec3 position;
    glm::vec3 scale;
    glm::quat oriention;
    Node* parent = nullptr;
    std::vector<Node*> children;
};

}
}
#endif