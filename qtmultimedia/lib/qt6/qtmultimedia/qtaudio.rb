# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    module QtAudio
      # @!parse class Error      ; end
      # @!parse class State      ; end
      # @!parse class VolumeScale; end
      rubyqt6_declare_enum_under QtAudio, QtAudio::Error
      rubyqt6_declare_enum_under QtAudio, QtAudio::State
      rubyqt6_declare_enum_under QtAudio, QtAudio::VolumeScale
    end
  end
end
