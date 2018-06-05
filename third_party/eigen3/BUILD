licenses([
    "reciprocal",  # MPL2
    "notice",  # Portions BSD
])

exports_files(["LICENSE"])

cc_library(
    name = "eigen3",
    hdrs = ["Eigen/Dense"],
    visibility = ["//visibility:public"],
    deps = ["@eigen_archive//:eigen"]
)