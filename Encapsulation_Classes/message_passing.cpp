#include <iostream>
#include <string>

using namespace std;

class Server
{
public:
    void receive(const string &message)
    {
        cout << "Server received: " << message << "\n";
        lastMessage_ = message;
    }

    const string &lastMessage() const { return lastMessage_; }

private:
    string lastMessage_;
};

class Client
{
public:
    explicit Client(string name) : name_(std::move(name)) {}

    void send(Server &server, const string &payload) const
    {
        server.receive(name_ + ": " + payload);
    }

private:
    string name_;
};

int main()
{
    Server server;
    Client c1("Client1");
    c1.send(server, "Hello");
    c1.send(server, "Status?\n");
    cout << "Last message stored: " << server.lastMessage() << "\n";
    return 0;
}
