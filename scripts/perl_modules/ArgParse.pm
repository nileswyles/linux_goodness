package ArgParse;
use strict;
use warnings;

sub parse {
	my %argh = {};
	my $prev_key = "";
	for (my $i = 0; $i < $#ARGV; $i++) {
		if ($ARGV[$i] =~ /-(.+)/) {
			$prev_key = $ARGV[$i];
			$argh{$prev_key} = 1;
		} elsif ($prev_key eq "$ARGV[$i - 1]") {
			# if start of key_value
			$argh{$prev_key} = "$ARGV[$i]";
		} else {
			# support (unquoted?) spaces in key_value pairs
			$argh{$prev_key} .= " $ARGV[$i]";
		}
	}
	return (%argh); # as an alternative to return \%argh (ref)
}
1;
