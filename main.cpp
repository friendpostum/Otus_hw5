#include "controller.h"
#include "model.h"
#include "interface.h"


struct Viewer : IViewer, public std::enable_shared_from_this<Viewer> {

    static std::shared_ptr<Viewer> create() {
        return std::shared_ptr<Viewer>{new Viewer{}};
    }

    std::shared_ptr<Controller> createDoc() {
        return std::make_shared<Controller>(shared_from_this());
    }

    std::shared_ptr<Controller> importDoc(const std::string &path) {
        return std::make_shared<Controller>(shared_from_this(), path);
    }

    void update(std::string msg) override {
        std::cout << msg << std::endl;
    }

private:
    Viewer() = default;
};


int main() {

    auto ui = Viewer::create();

    auto doc1 = ui->importDoc("doc.svg");
    auto doc2 = ui->createDoc();
    doc2->createEllipse();
    doc2->createRectangle();
    doc2->selectShape();
    doc2->deleteShape();
    doc2->exportDoc();

    return 0;
}
