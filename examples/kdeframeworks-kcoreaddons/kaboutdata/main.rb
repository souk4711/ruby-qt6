# frozen_string_literal: true

require 'qt6/kdeframeworks'

app = QCoreApplication.new

me = KAboutPerson.new("Nicolas Fella", "Author", "nicolas.fella@kde.org")
about = KAboutData.new("myapp", "My Application", "1.0")
about.add_author(me)
KAboutData.set_application_data(about)

puts("Hello, this is #{about.display_name} #{about.version}, written by #{about.authors[0].name}.")
puts("Hello, from QApp #{QCoreApplication.application_name} #{QCoreApplication.application_version}.")
