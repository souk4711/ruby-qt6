# frozen_string_literal: true

module RubyQt6
  module KCoreAddons
    # @see https://api.kde.org/kaboutperson.html
    class KAboutPerson
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param name [String, QString]
      # @param task [String, QString]
      # @param email [String, QString]
      # @param webaddress [String, QString]
      # @param avatar [String, QString, QUrl]
      # @return [KAboutPerson]
      def initialize(name = "", task = "", email = "", webaddress = "", avatar = "")
        _initialize(T.to_qstr(name), T.to_qstr(task), T.to_qstr(email), T.to_qstr(webaddress), T.to_qurl(avatar))
      end
    end
  end
end
