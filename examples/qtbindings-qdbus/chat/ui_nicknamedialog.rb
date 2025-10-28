# frozen_string_literal: true

class Ui_NicknameDialog
  def initialize(parent)
    loader = QUiLoader.new
    @widget = loader.load(QFile.new('./chatsetnickname.ui'), parent)
  end

  def cancel_button
    @widget.find_child('cancelButton')
  end

  def nickname
    @widget.find_child('nickname')
  end

  def exec
    @widget.exec
  end
end
