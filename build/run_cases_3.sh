#!/bin/bash

# 指定测试案例文件夹路径
testcase_folder="../test/cases_3"

# 指定输出文件夹路径
output_folder="../out/case_3"

# 创建输出文件夹（如果不存在）
mkdir -p "$output_folder"

# 获取当前时间
submit_time=$(date +"%Y-%m-%d %H:%M:%S")

# 打印测试提交时间
echo "Test Submission Time: $submit_time"

# 创建日志文件
log_file="$output_folder/case_3.log"
touch "$log_file"

# 遍历测试案例文件夹中的所有 .c 文件
for file in "$testcase_folder"/*.c; do
    filename=$(basename "$file")
    filename="${filename%.*}"
    asm_file="$output_folder/$filename.asm"

    echo "Running testcase: $file" >> "$log_file"
    # ./../submission/Compilerlab2 "$file" > "$asm_file"
    ./tcc "$file" > "$asm_file"
    spim -file "../out/case_3/$filename.asm" >> "$log_file"
    echo "---------------------------------------" >> "$log_file"
done