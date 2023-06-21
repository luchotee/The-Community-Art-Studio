# Create a python file for the Community Art Studio
f = open("CommunityArtStudio.py", "w+") 
 
# Begin writing code for the Community Art Studio
# Import necessary modules 
import sys
import os
import math
 
# Define global variables
community_art_studio_directory = '/home/user/Community_Art_Studio'
max_students_per_class = 20
 
# Create a function to check if there is enough space in the class
def is_space_in_class(class_size):
    if class_size < max_students_per_class:
        return True
    else: 
        return False
 
# Create a function to register a student
def register_student(name, email, phone_number):
    # Create a student dictionary
    student = {'name': name,
               'email': email,
               'phone_number': phone_number
              }
 
    # Create a file path for the student
    file_path = community_art_studio_directory + '/students/' + name + '.txt'
 
    # Write the student information to the file
    with open(file_path, "w") as f:
        f.write(str(student))
 
# Create a function to show the student directory
def show_directory():
    dir_path = community_art_studio_directory + "/students"
 
    # Get a list of students in the directory
    students = os.listdir(dir_path)
 
    # Print out a list of the students
    for student in students:
        print(student)
 
 
# Create a function to remove a student
def remove_student(name):
 
    # Create a file path for the student
    file_path = community_art_studio_directory + '/students/' + name + '.txt'
 
    # Check if the student file exists
    if os.path.exists(file_path):
        # Remove the student file 
        os.remove(file_path)
    else:
        print('No student with the name ' + name + ' was found.')
 
# Create a function to get the current size of a class
def get_class_size(class_name):
    file_path = community_art_studio_directory + '/classes/' + class_name + '.txt'
 
    # Check if the class file exists
    if os.path.exists(file_path):
        # Read the class file 
        with open(file_path, "r") as f:
            class_students = f.read().splitlines()
            return len(class_students)
    else:
        print('The class ' + class_name + ' does not exist.')
        return 0
 
# Create a function to add a student to a class
def add_student_to_class(name, class_name):
    # Create a file path for the class
    file_path = community_art_studio_directory + '/classes/' + class_name + '.txt'
 
    # Check if the class file exists
    if os.path.exists(file_path):
        # Get the current size of the class
        class_size = get_class_size(class_name)
        # Check if there is enough room in the class 
        if is_space_in_class(class_size):
            # Append the student to the class file
            with open(file_path, "a") as f:
                f.write(name + '\n')
        else: 
            print('The class ' + class_name + ' is full.')
    else:
        print('The class ' + class_name + ' does not exist.')
 
# Create a function to remove a student from a class
def remove_student_from_class(name, class_name):
    # Create a file path for the class
    file_path = community_art_studio_directory + '/classes/' + class_name + '.txt'
 
    # Read the class file 
    with open(file_path, "r") as f:
        class_students = f.read().splitlines()
 
    # Check if the student is in the class
    if name in class_students:
        # Remove the student from the class
        class_students.remove(name)
 
        # Write the updated class list to the file
        with open(file_path, "w") as f:
            for student in class_students:
                f.write(student + '\n')
    else:
        print('The student ' + name + ' is not in the class ' + class_name)
 
# Create a function to display the class list
def show_class_list(class_name):
    # Create a file path for the class
    file_path = community_art_studio_directory + '/classes/' + class_name + '.txt'
 
    # Check if the class file exists
    if os.path.exists(file_path):
        # Read the class file 
        with open(file_path, "r") as f:
            class_students = f.read().splitlines()
 
            print('Class ' + class_name + ':')
            for student in class_students:
                print(student)
    else:
        print('The class ' + class_name + ' does not exist.')
 
# Close the Python file
f.close()