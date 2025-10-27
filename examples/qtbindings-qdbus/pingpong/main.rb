# frozen_string_literal: true

pong = Process.spawn(RbConfig.ruby, 'pong.rb')
puts "#{__FILE__}: Process.spawn `ruby pong.rb`"

ping = Process.spawn(RbConfig.ruby, 'ping.rb', 'hello')
puts "#{__FILE__}: Process.spawn `ruby ping.rb hello`"

Process.waitpid(ping)
Process.waitpid(pong)
