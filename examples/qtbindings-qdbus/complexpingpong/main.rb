# frozen_string_literal: true

ping = Process.spawn(RbConfig.ruby, 'complexping.rb')
puts "#{__FILE__}: Process.spawn `ruby complexping.rb`"

pong = Process.spawn(RbConfig.ruby, 'complexpong.rb')
puts "#{__FILE__}: Process.spawn `ruby complexpong.rb`"

Process.waitpid(pong)
Process.waitpid(ping)
