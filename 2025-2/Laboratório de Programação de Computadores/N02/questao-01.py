import tkinter as tk

def add_item():
    item = input_item.get()
    quantity = input_quantity.get()
    if item and quantity.isdigit():
        with open("itens.txt", "a") as file:
            file.write(f"{item};{quantity}\n")
        input_item.delete(0, tk.END)
        input_quantity.delete(0, tk.END)
        print(f"Item '{item}' com quantidade '{quantity}' adicionado.")
    else:
        print("Por favor, insira um nome de item válido e uma quantidade numérica.")

def show_items():
    try:
        with open("itens.txt", "r") as file:
            items = file.readlines()
            itens_window = tk.Tk()
            itens_window.title("Itens Adicionados")
            itens_window.geometry("720x480")
            for line in items:
                item, quantity = line.strip().split(';')
                item_label = tk.Label(itens_window, text=f"Item: {item}, Quantidade: {quantity}")
                item_label.pack(pady=5)

    except FileNotFoundError:
        print("Nenhum item encontrado. O arquivo 'itens.txt' não existe.")

window = tk.Tk()
window.title("Questão 01")
window.geometry("720x480")

input_item_label = tk.Label(window, text="Nome do Item:")
input_item_label.pack(pady=10)
input_item = tk.Entry(window)
input_item.pack(pady=5)

input_quantity_label = tk.Label(window, text="Quantidade:")
input_quantity_label.pack(pady=10)
input_quantity = tk.Entry(window)
input_quantity.pack(pady=5)


add_button = tk.Button(window, text="Adicionar Item", command=add_item)
add_button.pack(pady=20)

show_button = tk.Button(window, text="Mostrar Itens", command=show_items)
show_button.pack(pady=5)
window.mainloop()