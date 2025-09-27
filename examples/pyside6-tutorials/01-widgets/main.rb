require 'qt6/all'

app = QApplication.new(ARGV)
label = QLabel.new('Hello World!')
label.show
app.exec
