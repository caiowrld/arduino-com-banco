from PyQt5 import uic, QtWidgets
import mysql.connector
import serial

arduino = serial.Serial('COM4', 9600)

banco = mysql.connector.connect(
    host = "localhost",
    user = "root",
    password = "",
    database = "estufa"
)

def cadastrar():
    if tela.LEDVm.isChecked():
        led = tela.LEDVm.text()
    elif tela.LEDVd.isChecked():
        led = tela.LEDVd.text()
    elif tela.LEDAm.isChecked():
        led = tela.LEDAm.text()
    else:
        led = "Nenhum LED foi informado"

    registro = banco.cursor()
    script = "INSERT INTO registroLeds(cor, dataHoraRegistro) VALUES (%s, current_timestamp());"
    dados = ([led])
    registro.execute(script, dados)
    banco.commit()

def enviar():
    if tela.LEDVm.isChecked():
        arduino.Write(b'V')
    elif tela.LEDVd.isChecked():
        arduino.Write(b'B')
    elif tela.LEDAm.isChecked():
        arduino.Write(b'R')

app = QtWidgets.QApplication([])
tela = uic.loadUi("LEDS.ui")

tela.BEnviar.clicked.connect(cadastrar)

tela.show()

app.exec_()