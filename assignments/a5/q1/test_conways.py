#!/usr/bin/env python3
import os
import subprocess
import sys

def compile_program():
    """Compile the Conway's Game of Life program"""
    print("Compiling conways.cc...")
    result = subprocess.run(["g++", "-std=c++17", "-Wall", "-Werror", "conways.cc", "-o", "conways"])
    if result.returncode != 0:
        print("Compilation failed!")
        sys.exit(1)
    print("Compilation successful!")

def test_conway(input_file):
    """Test Conway's Game of Life with a specific input file"""
    if not os.path.exists(input_file):
        print(f"Input file {input_file} not found!")
        return
    
    print(f"\nTesting with {input_file}:")
    print("-" * 40)
    
    # Create test commands: print initial state, step, print result
    commands = "p\ns\np\n"
    
    # Run the test
    process = subprocess.Popen(
        ["./conways"], 
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        text=True
    )
    
    # Read the input file
    with open(input_file, 'r') as f:
        input_content = f.read()
    
    # Send the input and commands
    stdout, _ = process.communicate(input_content + commands)
    
    # Print the output
    print(stdout)
    print("-" * 40)

def main():
    # Compile the program
    compile_program()
    
    # Test with all .in files
    input_files = [f for f in os.listdir('.') if f.endswith('.in')]
    
    if not input_files:
        print("No .in files found in the current directory!")
        return
    
    for input_file in input_files:
        test_conway(input_file)
    
    # Clean up
    os.remove("conways")
    print("All tests completed!")

if __name__ == "__main__":
    main()