#include <iostream>
#include <memory>

class Resource {
public:
    Resource(int id) : id_(id) { std::cout << "Resource " << id_ << " created\n"; }
    ~Resource() { std::cout << "Resource " << id_ << " destroyed\n"; }
    int get_id() const { return id_; }
private:
    int id_;
};

int main() {
    std::unique_ptr<Resource> r1 = std::make_unique<Resource>(1);
    std::shared_ptr<Resource> r2 = std::make_shared<Resource>(2);
    std::shared_ptr<Resource> r3 = r2;
    std::cout << "Ref count: " << r2.use_count() << "\n";
    std::unique_ptr<Resource> r4 = std::move(r1);
    return 0;
}
