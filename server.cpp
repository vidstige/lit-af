#include "httplib.h"

int main() {
    httplib::Server server;

    server.set_mount_point("/", "./");
    server.Get("/pass", [](const httplib::Request &, httplib::Response &res) {
        res.set_content("PASSED", "text/plain");
    });

    server.Get("/fail", [](const httplib::Request &, httplib::Response &res) {
        res.set_content("FAILED", "text/plain");
        res.status = 500;
    });

    server.listen("127.0.0.1", 8080);
    return 0;
}