// src/lib.rs
extern crate libc;
use libc::c_int;
use std::cell::RefCell;

thread_local! {
    static RUST_GLOBAL: RefCell<i32> = RefCell::new(0);
}

#[no_mangle]
pub extern "C" fn rust_global_set(value: c_int) {
    RUST_GLOBAL.with(|v| *v.borrow_mut() = value);
}

#[no_mangle]
pub extern "C" fn rust_global_get() -> c_int {
    RUST_GLOBAL.with(|v| *v.borrow())
}
