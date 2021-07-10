#include <cstdio>
#include <cstring>
#include <fstream>

#include "wasm3_cpp.h"
#include "wasm/test_prog.wasm.h"

int main(void)
{
    std::cout << "Loading WebAssembly..." << std::endl;

    /* Wasm module can also be loaded from an array */
    try {
        wasm3::environment env;
        wasm3::runtime runtime = env.new_runtime(1024);


        wasm3::module mod = env.parse_module(test_prog_wasm, test_prog_wasm_len);
        runtime.load(mod);

        wasm3::function atest_fn = runtime.find_function("allocate_test");
        wasm3::function test_fn = runtime.find_function("test");

        std::cout << "calling allocate_test ..." << std::endl;
        atest_fn.call<uint32_t>(1);

        std::cout << "calling allocate_test ..." << std::endl;
        atest_fn.call<uint32_t>(2);
    }
    catch(wasm3::error &e) {
        std::cerr << "WASM3 error: " << e.what() << std::endl;
        return 1;
    }
    std::cout << "done" << std::endl;

    return 0;
}
