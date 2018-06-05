py_binary(
    name = "compiler",
    srcs = ["main.py"],
    main = "main.py",
    data = ["//src/templates"],
    args = [
        # Command line options will override the ones below
         "-i input",
         "-o output",
         "-t $(locations //src/templates)",
         "-d ../out"
    ]
)
