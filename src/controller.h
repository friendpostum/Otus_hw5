#pragma once
#include <iostream>
#include <memory>
#include "model.h"

struct Controller {
    explicit Controller(IViewer* ui) {
        document = std::make_shared<Model>("Created doc");
        document->subscribe(ui);
        std::cout << "create new document  " << '\n';
    }

    explicit Controller(IViewer* ui, const std::string &path) {
        document = std::make_shared<Model>("Imported doc");
        document->subscribe(ui);
        std::cout << "import document from " << path << '\n';
    }

    void createEllipse(){
        document->addShape(std::make_shared<Ellipse>("New ellipse"));
    };

    void createRectangle(){
        document->addShape(std::make_shared<Rectangle>("New rectangle"));
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
    std::shared_ptr<Model> document = nullptr;
};


