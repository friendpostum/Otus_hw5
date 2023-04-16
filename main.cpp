#include <memory>
#include "shapes.h"

struct DocCtrl {
private:
    std::shared_ptr<Document> document = nullptr;

public:
    std::unique_ptr<Tools> tools = nullptr;

    void createDoc(const std::string& name){
        document = std::make_shared<Document>();
        tools = std::make_unique<Tools>(document);
        document->setName(name);
    };
    void exportToFile(const std::string& path){};
    void importFromFile(const std::string& path){};
};


int main() {
    DocCtrl doc;
    doc.createDoc("New doc");
    doc.exportToFile("doc.svg");
    doc.importFromFile("doc.svg");

    doc.tools->createEllipse();
    doc.tools->createRectangle();
    doc.tools->selectShape();
    doc.tools->deleteSelectedShape();

    return 0;
}
