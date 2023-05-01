#pragma once
#include <iostream>
#include <memory>
#include "model.h"

struct Controller {
    explicit Controller() {
        document = std::make_shared<Document>();
        std::cout << "create new document  " << '\n';
    }

    explicit Controller(const std::string &path) {
        document = std::make_shared<Document>();
        std::cout << "import document from " << path << '\n';
    }

    void createEllipse(){
        document->addShape(std::make_unique<Ellipse>("New ellipse"));
    };

    void createRectangle(){
        document->addShape(std::make_unique<Rectangle>("New rectangle"));
    };

    void select(){
        int posX = 50;
        int posY = 50;
        document->selectShape(posX, posY);
    };

    void remove(){
        document->removeShape();
    };

private:
    std::shared_ptr<Document> document = nullptr;
};


