cc_test(
    name = "multiply_col_broadcast",
    size = "small",
    srcs = ["test.cc"],
    copts = ["-Iexternal/gtest/include"],
    deps = ["@gtest//:main", ":brook", "//test:utils"],
    data = [":test_files"]
)

cc_library(
    name = "brook",
    srcs = ["brook.cc"],
    hdrs = ["brook.h"],
    deps = ["//third_party/eigen3"],
    visibility = ["//visibility:private"]
)

filegroup(
    name = "test_files",
    srcs = [
        "tf.in", 
        "tf.out"
    ]
)