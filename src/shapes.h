#pragma once

#include <string>

class Shape {
public:
    virtual ~Shape() = default;

    void setName(const std::string &name_) {}

protected:
    Shape(const std::string &name) {}
};

class Ellipse : public Shape {
    std::string name;
public:
    Ellipse(const std::string &name) : Shape(name) {}

};

class Rectangle : public Shape {
public:
    Rectangle(const std::string &name) : Shape(name) {}

};

class Document {
    std::string name;
public:
    void setName(const std::string& name_) {
        name = name_;
    }

    void addShape(const std::shared_ptr<Shape>& shape) {}

    void deleteShape(const std::shared_ptr<Shape>& shape) {}

    std::shared_ptr<Shape> selectShape(double positionX, double positionY) {
        return nullptr;
    }
};

struct Tools {
    std::shared_ptr<Shape> selectedShape = nullptr;
    std::shared_ptr<Document> document;

    explicit Tools(std::shared_ptr<Document> p) : document(std::move(p)) {}

    void createEllipse(){
        document->addShape(std::make_unique<Ellipse>("New ellipse"));
    };

    void createRectangle(){
        document->addShape(std::make_unique<Rectangle>("New rectangle"));
    };

    void selectShape(){
        double posX = 50;
        double posY = 50;
        selectedShape = document->selectShape(posX, posY);
    };

    void deleteSelectedShape(){
        document->deleteShape(selectedShape);
        selectedShape = nullptr;
    };

};