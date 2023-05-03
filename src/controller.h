#pragma once
#include <iostream>
#include <memory>
#include "interface.h"
#include "model.h"

struct Controller {
    explicit Controller(std::shared_ptr<IViewer> ui) {
        document = std::make_shared<Model>("Created doc");
        document->subscribe(std::move(ui));
        std::cout << "Create new document  " << '\n';
    }

    explicit Controller(std::shared_ptr<IViewer> ui, const std::string &path) {
        document = std::make_shared<Model>("Imported doc");
        document->subscribe(std::move(ui));
        std::cout << "Import document from " << path << '\n';
    }

    void exportDoc() {
        document->exportDoc();
    }

    void createEllipse(){
        document->addShape(std::make_shared<Ellipse>("New ellipse"));
    };

    void createRectangle(){
        document->addShape(std::make_shared<Rectangle>("New rectangle"));
    };

    void selectShape(){
        int posX = 50;
        int posY = 50;
        document->selectShape(posX, posY);
    };

    void deleteShape(){
        document->removeShape();
    };

private:
    std::shared_ptr<Model> document = nullptr;
};


