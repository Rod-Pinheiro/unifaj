import tkinter as tk


def start_timer():
    try:
        start_button.config(state=tk.DISABLED)
        total_seconds = int(input_timer.get())
        for remaining in range(total_seconds, -1, -1):
            timer_value.config(text=f"{remaining} segundos")
            window.update()
            window.after(1000)
        timer_value.config(text="Tempo esgotado!")
        start_button.config(state=tk.NORMAL)
    except ValueError:
        print("Por favor, insira um número válido de segundos.")

window = tk.Tk()
window.title("Questão 02")
window.geometry("720x480")

input_timer_label = tk.Label(window, text="Defina o tempo (segundos):")
input_timer_label.pack(pady=10)
input_timer = tk.Entry(window)
input_timer.pack(pady=5)

timer_value_label = tk.Label(window, text="Tempo definido:")
timer_value_label.pack(pady=10)
timer_value = tk.Label(window, text="0 segundos")
timer_value.pack(pady=5)

start_button = tk.Button(window, text="Iniciar" , command=start_timer)
start_button.pack(pady=20)


window.mainloop()