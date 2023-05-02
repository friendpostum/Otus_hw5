#include "controller.h"
#include "model.h"
#include "viewer.h"


struct Viewer : IViewer {
    std::shared_ptr<Controller> createDoc() {
        return std::make_shared<Controller>();
    }

    std::shared_ptr<Controller> importDoc(const std::string &path) {
        return std::make_shared<Controller>(path);
    }

    void exportDoc(const std::shared_ptr<Controller> &, const std::string &path) {
        std::cout << "export document to " << path << '\n';
    }

    void createEllipse(const std::shared_ptr<Controller> & doc){
        doc->createEllipse();
    };

    void createRectangle(const std::shared_ptr<Controller> & doc){
        doc->createRectangle();
    };

    void selectShape(const std::shared_ptr<Controller> & doc) {
        doc->select();
    }

    void deleteShape(const std::shared_ptr<Controller> & doc) {
        doc->remove();
    }


    Viewer(Model *file) : model{file} {
        file->subscribe(this);
    }

    void update() override {
        std::cout << model->message()<< std::endl;
    }
private:
    Model *model;
};


int main() {
    Model model;
    Viewer ui(&model);

    auto doc = ui.createDoc();
    auto doc1 = ui.importDoc("doc.svg");
    ui.createEllipse(doc);
    ui.createRectangle(doc);
    ui.selectShape(doc);
    ui.deleteShape(doc);

    return 0;
}
