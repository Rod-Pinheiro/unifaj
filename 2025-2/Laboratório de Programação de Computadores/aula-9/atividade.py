import tkinter as tk

def click():
    text = tk.Label(window,text="Hello World!")
    text.pack(padx=20,pady=20)
    
window = tk.Tk()
window.title("Pyhton GUI")
window.geometry("1280x720")

texto_label = tk.Label(window,text="Clique no botão abaixo:")
texto_label.pack(padx=20,pady=20)

botao = tk.Button(window,text="Clique aqui", command=click)
botao.pack(padx=22, pady=20)

window.mainloop()
