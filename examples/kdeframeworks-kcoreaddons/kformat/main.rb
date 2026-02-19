# frozen_string_literal: true

require 'qt6/kdeframeworks'

formatter = KFormat.new
puts(formatter.format_byte_size(1234567))
puts(formatter.format_decimal_duration(54353534))
puts(formatter.format_distance(3.41, KFormat::MetricDistanceUnits))
puts(formatter.format_duration(1234567, KFormat::AbbreviatedDuration))
puts(formatter.format_spellout_duration(1234567))
