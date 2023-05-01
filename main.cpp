#include "controller.h"

struct Viewer{
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

    void update()  {
        //std::cout << "switch report '" << m_name << "' to lang " << lang << std::endl;
    }
};

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

int main() {
    auto doc = createDoc();
    auto doc1 = importDoc("doc.svg");
    createEllipse(doc);
    createRectangle(doc);
    selectShape(doc);
    deleteShape(doc);

    return 0;
}
