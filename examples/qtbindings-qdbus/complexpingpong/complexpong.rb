# frozen_string_literal: true

require 'qt6/all'

class Pong < RubyQt6::Bando::QDBusAbstractAdaptor
  q_object do
    classinfo 'D-Bus Interface', 'com.trolltech.QtDBus.ComplexPong.Pong'
    slot 'quit()'
    slot 'QString value()'
    slot 'set_value(QString)'
    slot 'QDBusVariant query(QString)'
  end

  def quit
    QTimer.single_shot(0, $qApp, :quit)
  end

  def value
    @m_value
  end

  def set_value(new_value)
    @m_value = new_value
  end

  def query(query)
    q = query.to_s.downcase
    if q == 'hello'
      return QDBusVariant.new('World')
    elsif q == 'ping'
      return QDBusVariant.new('Pong')
    elsif q == 'the answer to life, the universe and everything'
      return QDBusVariant.new(42)
    elsif !q.index('unladen swallow').nil?
      return QDBusVariant.new(11.0) unless q.index('european').nil?

      return QDBusVariant.new('african or european?')
    end

    QDBusVariant.new("Sorry, I don't know the answer")
  end
end

app = QCoreApplication.new

obj = QObject.new
pong = Pong.new(obj)
pong.set_value('initial value')
QDBusConnection.session_bus.register_object('/', obj)

unless QDBusConnection.session_bus.register_service('com.trolltech.QtDBus.PingExample')
  warn("#{__FILE__}: Cannot register service: %s" % QDBusConnection.session_bus.last_error.message)
  exit(1)
end

app.exec
