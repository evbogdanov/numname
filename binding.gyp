{
    "targets": [
        {
            "target_name": "numname",
            "sources": [
                "./cpp/numname.cpp",
                "./cpp/numname_wrap.cpp"
            ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ]
        }
    ]
}
