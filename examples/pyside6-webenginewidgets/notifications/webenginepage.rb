# frozen_string_literal: true

class WebEnginePage < RubyQt6::Bando::QWebEnginePage
  q_object do
    slot 'on_permission_requested(QWebEnginePermission)'
  end

  def accept_navigation_request(url, _type, _is_main_frame)
    return true if url.scheme != 'https'

    QDesktopServices.open_url(url)
    false
  end

  def on_permission_requested(permission)
    return if permission.permission_type != QWebEnginePermission::PermissionType::Notifications

    permission.grant
  end
end
