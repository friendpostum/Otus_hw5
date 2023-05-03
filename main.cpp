#include "controller.h"
#include "model.h"
#include "viewer.h"


struct Viewer : IViewer {

    std::shared_ptr<Controller> createDoc() {
        return std::make_shared<Controller>(this);
    }

    std::shared_ptr<Controller> importDoc(const std::string &path) {
        return std::make_shared<Controller>(this, path);
    }

    void update(std::string msg) override {
        std::cout << msg << std::endl;
    }
};


int main() {

    Viewer ui;

    auto doc1 = ui.importDoc("doc.svg");
    auto doc2 = ui.createDoc();
    doc2->createEllipse();
    doc2->createRectangle();
    doc2->select();
    doc2->remove();

    return 0;
}
