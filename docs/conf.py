import subprocess, os

project = "Touch Typing"
copyright = "MIT License, Copyright (c) 2020 Oleksandr Kozlov"
author = "Oleksandr Kozlov"
release = "v0.1.0"
html_theme = 'sphinx_rtd_theme'
extensions = [ "breathe" ]
breathe_default_project = "Touch Typing"

def configure_doxyfile(source_dir):
    with open('Doxyfile.in', 'r') as file :
        filedata = file.read()

    filedata = filedata.replace('@PROJECT_SOURCE_DIR@', source_dir)

    with open('Doxyfile', 'w') as file:
        file.write(filedata)

read_the_docs_build = os.environ.get('READTHEDOCS', None) == 'True'

breathe_projects = {}

if read_the_docs_build:
    source_dir = ".."
    doxygen_dir = "/build/docs/doxygen"
    try:
        os.makedirs(source_dir + doxygen_dir)
    except:
        print("Creation of the directory failed")

    configure_doxyfile(source_dir)
    subprocess.call('doxygen', shell=True)
    breathe_projects["Touch Typing"] = source_dir + doxygen_dir + "/xml"
