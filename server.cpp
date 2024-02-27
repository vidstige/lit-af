#include "httplib.h"

void pass(const httplib::Request &, httplib::Response &res) {
    res.set_content("PASSED", "text/plain");
}

void fail(const httplib::Request &, httplib::Response &res) {
    res.set_content("FAILED", "text/plain");
    res.status = 500;
}

int main() {
    httplib::Server server;
    server.set_mount_point("/", "./");
    server.Get("/pass", pass);
    server.Get("/fail", fail);
    server.listen("127.0.0.1", 8080);
    return 0;
}