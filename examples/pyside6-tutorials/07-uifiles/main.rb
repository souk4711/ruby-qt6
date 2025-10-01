require "qt6/all"

app = QApplication.new(ARGV)
loader = QUiLoader.new
widget = loader.load(QFile.new("./mainwindow.ui"))
widget.show
app.exec
