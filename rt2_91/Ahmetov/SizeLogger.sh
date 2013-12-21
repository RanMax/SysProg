#!/bin/bash
echo `date '+%Y-%m-%d %H:%M'` \| `du -sh $1 | cut -f1`»$2
