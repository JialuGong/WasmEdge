//! How to use this crate
//! # Adding this as a dependency
//! ```rust, ignore
//! [dependencies]
//! wasmedge_hostfunctionexample_interface = "^1.0.0"
//! ```
//!
//! # Bringing this into scope
//! ```rust, ignore
//! use wasmedge_hostfunctionexample_interface::*;
//! ```

pub mod wasmedge_hostfunctionmyhost {
    #[link(wasm_import_module = "host_function_my_host")]
    extern "C" {
        pub fn host_function_my_host_print_socket(packet_amount: i32);
    }
}

pub fn print_socket(packet_amount: i32) {
    unsafe {
        wasmedge_hostfunctionmyhost::host_function_my_host_print_socket(packet_amount);
    }
}
