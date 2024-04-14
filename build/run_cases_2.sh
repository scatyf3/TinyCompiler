#!/bin/bash

# 指定测试案例文件夹路径
testcase_folder="../test/cases_2"

# 指定输出文件夹路径
output_folder="../out/case_2"

# 创建输出文件夹（如果不存在）
mkdir -p "$output_folder"

# 遍历测试案例文件夹中的所有 .c 文件
for file in "$testcase_folder"/*.c; do
    filename=$(basename "$file")
    filename="${filename%.*}"
    asm_file="$output_folder/$filename.asm"
    log_file="$output_folder/case_2.log"

    echo "Running testcase: $file"
    ./tinyCompiler "$file" > "$asm_file"
    spim -file "../out/case_2/$filename.asm" >> "$log_file"
    echo "---------------------------------------"
done