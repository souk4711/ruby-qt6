# frozen_string_literal: true

require 'qt6/all'

class Communicate < RubyQt6::Bando::QObject
  q_object do
    signal 'speak_int(int)'
    signal 'speak_str(QString)'
    slot 'say_hello_int(int)'
    slot 'say_hello_str(QString)'
  end

  def initialize
    super

    speak_int.connect(self, :say_hello_int)
    speak_str.connect(self, :say_hello_str)
  end

  def say_hello_int(arg)
    puts "This is a number: #{arg}"
  end

  def say_hello_str(arg)
    puts "This is a string: #{arg}"
  end
end

QApplication.new
someone = Communicate.new
someone.speak_int.emit(10)
someone.speak_str.emit('Hello everybody!')
