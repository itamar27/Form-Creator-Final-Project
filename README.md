Handlers: 	Barak Daniel - 204594329
		Itamar Yarden - 204289987

## Compilation and run

For the compilation of the application please use the below:

g++ ./Model/Field/InputField.cpp ./Model/Field/ListSelectField.cpp ./Model/Field/MultiChoiceField.cpp ./Model/Field/SingleChoiceField.cpp .\Model\Field\FreeTextField.cpp .\Model\Component\Component.cpp .\Model\Form\HtmlForm.cpp .\Model\HtmlFormModel.cpp .\View\CLI.cpp .\Controller\MyController.cpp .\FormCreatorCLI.cpp -o FormCreator.exe

Note: you can also find this compilation line in the FormCreatorCLI.cpp file.


# Form-Creator-Final-Project

An automatic form creator stand alone application for "Methods in software engineering" course 


## Welcome!

In the form creator application you can create forms templates containing components and fields.


### When ever you want, type 'help' in the application to get a brief guide.
## How to use it?

When you start the first time you will want to create 'new form', and when u did you can start adding components to it.
Each component in the form can hold as many fields as you like and you can always change their names and adjust their order,
and ofcourse adding new ones and removing existing ones.
When you will add a field for the first time, you will choose to which component you want to add it to, then give it a name
and finally choose a type (you can see 'Field types' section below).
At any point in the application you can load or save your form and you can also generate it (HTML form).
When exiting the application via the 'exit' command, your current progress will be saved and you can continue from the same
point when entering the application again.


## Commands list

1.	add component
2.	add field
3.	adjust component order
4.	adjust field order
5.	change component name
6.	change form name
7.	exit
8.	generate form
9.	load form
10.	new form
11.	remove component
12.	remove field
13.	save form
14.	set field data
15.	show current progress


## Field types

1. InputField -		a simple text input field (example - username).
2. FreeTextField -	a large free text input field (example - about yourself).
3. SingleChoiceField -	a field with set of values where you can choose only one (example - gender).
4. MultiChoiceField - 	a field with set of values where you can choose as many as you like (example - hobbies).
5. ListSelectField -	a field with set of values where you can choose only one from a drop list (example - location).