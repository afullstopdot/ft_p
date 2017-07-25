# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    close_port.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarquez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/25 18:06:36 by amarquez          #+#    #+#              #
#    Updated: 2017/07/25 18:50:15 by amarquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## number pattern

re='^[0-9]+$'

## ask for port number

printf "PORT #: ";

## assign port number

read -p "" port

## check if valid port number

if [ "$port" -eq "$port" ] 2>/dev/null; then

	# get output from lsof ( including PID )

	lsof="$(lsof -i :$port)"

	printf "$lsof";

else

	# not a valid port number

	printf "error: not a valid port number";

fi
