      subroutine fortfileopen
     -(lun, fname, status, form, acces, blank, recl)

      integer lun, recl
      character*(*) fname, status, form, acces, blank

      open(UNIT=lun, FILE=fname, STATUS=status, FORM=form,
     -     BLANK=blank, ACCESS=acces, RECL=recl)

      return
      end

*******************************************************************************

      subroutine fortfileclose(lun, status)

      integer lun
      character*(*) status

      close(lun, STATUS=status)

      return
      end
