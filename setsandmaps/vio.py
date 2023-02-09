import tkinter
root = tkinter.Tk()

def ini_finestra():
	finestra = tkinter.Canvas(bg="green", width=600, height=600)
	finestra.pack()
	finestra.mainloop()


ini_finestra()
