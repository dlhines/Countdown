#include <iostream>
#include <cpr/cpr.h>

int main() {
  cpr::Response r = cpr::Get(cpr::Url{"https://infnx.space/countdown/bin/header_template.html"},
  cpr::VerifySsl(false));

  std::cout << r.url << std::endl; // http://www.httpbin.org/get
  std::cout << r.status_code << std::endl; // 200
  std::cout << r.text << std::endl;
  std::cout << r.error.message << std::endl;
}
