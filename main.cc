#include <string>
#include <iostream>
using namespace std;

#include <json.hpp>
using nlohmann::json;

#include <endpoints.hpp>
using namespace endpoints;

auto print_result(const json &result) -> void {
  if (result != nullptr)
    cout << result.dump(4) << endl;
}

int main(int argc, char** argv) {
  const Params& params = {
    //B bid A ask
    { "price", "BA" },
    { "from", "2017-10-01T15:17:00Z" },
    //M1 1 minute, S1 1 second, D 1 day
    { "granularity", "D" }
  };

  print_result(instrument::candles("USD_JPY", params));
}
