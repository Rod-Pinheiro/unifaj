import tkinter as tk
import uuid
import json
from tkinter import messagebox

editing_user_id = None
dialog_button = None

def create_file(filename, user_data=None):
    with open(filename, 'a') as file:
        file.write(json.dumps(user_data) + '\n' if user_data else "")

def read_file(filename):
    with open(filename, 'r') as file:
        data = file.read()
        print(data)
    return data

def clear_frame(frame):
    for widget in frame.winfo_children():
        widget.destroy()

def create_frame(parent, label_text):
    frame = tk.Frame(parent)
    frame.pack(fill="x", pady=5)
    label = tk.Label(frame, text=label_text, width=10, anchor="w")
    label.pack(side="left")
    entry = tk.Entry(frame)
    entry.pack(side="left", expand=True, fill="x", padx=(10, 0))
    return entry

def create_form(parent, label_text):
    global dialog_button
    forms = tk.Frame(parent)
    forms.config(padx=20, pady=20)
    forms.pack(pady=20)

    label = tk.Label(forms, text=label_text)
    label.config(font=("Arial", 16))
    label.pack(pady=10)

    dialog_button = tk.Button(forms, text="Adicionar Usuário", command=add_user)
    dialog_button.pack(pady=20, side="bottom")
    return forms

def update_user():
    global editing_user_id, dialog_button
    
    user = {
        'id': editing_user_id,
        'name': name_entry.get(),
        'surname': surname_entry.get(),
        'phone': phone_entry.get(),
        'address': address_entry.get(),
        'zip_code': zip_entry.get(),
    }

    if all(user.values()):
        update_user_in_file("data.txt", editing_user_id, user)
        messagebox.showinfo("Success", f"User updated:\nName: {user['name']} {user['surname']}\nPhone: {user['phone']}\nAddress: {user['address']}\nZip: {user['zip_code']}")
        

        editing_user_id = None
        dialog_button.config(text="Adicionar Usuário", command=add_user)
        
        if users_frame:
            clear_frame(users_frame)
            print_users(users_frame)
            clean_entries()
    else:
        messagebox.showerror("Error", "Preencha todos os campos antes de atualizar o usuário.")

def add_user(): 
    user = {
        'id': str(uuid.uuid4()),
        'name': name_entry.get(),
        'surname': surname_entry.get(),
        'phone': phone_entry.get(),
        'address': address_entry.get(),
        'zip_code': zip_entry.get(),
    }

    if all(user.values()):
        create_file("data.txt", user)
        messagebox.showinfo("Success", f"User added:\nName: {user['name']} {user['surname']}\nPhone: {user['phone']}\nAddress: {user['address']}\nZip: {user['zip_code']}")
        if users_frame:
            clear_frame(users_frame)
            print_users(users_frame)
            clean_entries()
    else:
        messagebox.showerror("Error", "Preencha todos os campos antes de adicionar o usuário.")
 
def print_users(frame):
    users = read_file("data.txt")
    if users:
        label = tk.Label(frame, text="Usuários Cadastrados:")
        label.config(font=("Arial", 14))
        label.pack(pady=5)
        for line in users.split('\n'):
            if line.strip():
                try:
                    user_dict = json.loads(line)
                    user_row = tk.Frame(frame)
                    user_row.pack(fill="x", pady=2)
                    content_frame = tk.Frame(user_row)
                    content_frame.pack(expand=True, anchor="center")
                    user_label = tk.Label(content_frame, text=f"Usuário: {user_dict['name']} {user_dict['surname']}")
                    user_label.pack(side="left")
                    edit_button = tk.Button(content_frame, text="Editar", command=lambda uid=user_dict['id']: edit_user(uid))
                    edit_button.pack(side="left", padx=(10, 0))
                    print(f"User: {user_dict['name']} {user_dict['surname']}")
                except (ValueError, json.JSONDecodeError):
                    print(f"Error parsing line: {line}")    

def update_user_in_file(filename, user_id, updated_user):
    users = []
    with open(filename, 'r') as file:
        for line in file:
            if line.strip():
                try:
                    user_dict = json.loads(line)
                    if user_dict['id'] == user_id:
                        users.append(json.dumps(updated_user))
                    else:
                        users.append(line.strip())
                except (ValueError, json.JSONDecodeError):
                    users.append(line.strip())
    
    with open(filename, 'w') as file:
        for user_line in users:
            file.write(user_line + '\n')
            
def edit_user(user_id):
    global editing_user_id, dialog_button
    
    with open("data.txt", 'r') as file:
        for line in file:
            if line.strip():
                try:
                    user_dict = json.loads(line)
                    if user_dict['id'] == user_id:
                        name_entry.delete(0, tk.END)
                        name_entry.insert(0, user_dict['name'])
                        
                        surname_entry.delete(0, tk.END)
                        surname_entry.insert(0, user_dict['surname'])
                        
                        phone_entry.delete(0, tk.END)
                        phone_entry.insert(0, user_dict['phone'])
                        
                        address_entry.delete(0, tk.END)
                        address_entry.insert(0, user_dict['address'])
                        
                        zip_entry.delete(0, tk.END)
                        zip_entry.insert(0, user_dict['zip_code'])
                        
                        editing_user_id = user_id
                        dialog_button.config(text="Atualizar Usuário", command=update_user)
                        break
                except (ValueError, json.JSONDecodeError):
                    continue

def clean_entries():
    name_entry.delete(0, tk.END)
    surname_entry.delete(0, tk.END)
    phone_entry.delete(0, tk.END)
    address_entry.delete(0, tk.END)
    zip_entry.delete(0, tk.END)

window = tk.Tk()
window.title("Adiciona Usuário")
window.geometry("1280x720")

forms = create_form(window, "Formulário de Adição de Usuário")

name_entry = create_frame(forms, "Nome:")

surname_entry = create_frame(forms, "Sobrenome:")

phone_entry = create_frame(forms, "Telefone:")

address_entry = create_frame(forms, "Endereço:")

zip_entry = create_frame(forms, "CEP:")

users_frame = tk.Frame(window)
users_frame.pack(fill="x", pady=5)

create_file("data.txt")
print_users(users_frame)



window.mainloop()
