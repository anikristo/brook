workspace(name = "brook")

new_http_archive(
      name = "eigen_archive",
      urls = [
          "http://mirror.bazel.build/bitbucket.org/eigen/eigen/get/f3a22f35b044.tar.gz",
          "https://bitbucket.org/eigen/eigen/get/f3a22f35b044.tar.gz",
      ],
      sha256 = "ca7beac153d4059c02c8fc59816c82d54ea47fe58365e8aded4082ded0b820c4",
      strip_prefix = "eigen-eigen-f3a22f35b044",
      build_file = "third_party/eigen.BUILD"
  )

new_http_archive(
    name = "gtest",
    url = "https://github.com/google/googletest/archive/release-1.7.0.zip",
    sha256 = "b58cb7547a28b2c718d1e38aee18a3659c9e3ff52440297e965f5edffe34b6d0",
    build_file = "third_party/gtest.BUILD",
    strip_prefix = "googletest-release-1.7.0",
)