#include <iostream>
#include <memory>
#include <string>

using namespace std;

class FileHandle
{
public:
    explicit FileHandle(string path) : path_(std::move(path))
    {
        cout << "Opening resource: " << path_ << "\n";
    }

    ~FileHandle()
    {
        cout << "Closing resource: " << path_ << "\n";
    }

    FileHandle(const FileHandle &) = delete;
    FileHandle &operator=(const FileHandle &) = delete;

private:
    string path_;
};

int main()
{
    {
        FileHandle fh("data.txt");
        auto ptr = make_unique<FileHandle>("temp.txt");
    }
    cout << "Scope ended; destructors ran." << "\n";
    return 0;
}
