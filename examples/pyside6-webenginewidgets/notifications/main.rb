# frozen_string_literal: true

require 'qt6/all'
require_relative 'notificationpopup'
require_relative 'webenginepage'

QApplication.set_organization_name('QtProject')

app = QApplication.new(ARGV)
view = QWebEngineView.new

page = WebEnginePage.new(view)
view.set_page(page)
view.page.permission_requested.connect(page, :on_permission_requested)

popup = NotificationPopup.new(view)
profile = view.page.profile
profile.set_notification_presenter(->(notification) { popup.present(notification) })

view.resize(640, 480)
view.show
view.set_url(QUrl.from_local_file(File.join(__dir__, 'resources/index.html')))
app.exec

# resolve `Release of profile requested but WebEnginePage still not deleted. Expect troubles !`
view.delete_now
